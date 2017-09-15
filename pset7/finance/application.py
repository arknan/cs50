from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session, url_for
from flask_session import Session
from passlib.apps import custom_app_context as pwd_context
from tempfile import mkdtemp
from datetime import datetime

from helpers import *

# configure application
app = Flask(__name__)

# ensure responses aren't cached
if app.config["DEBUG"]:
    @app.after_request
    def after_request(response):
        response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
        response.headers["Expires"] = 0
        response.headers["Pragma"] = "no-cache"
        return response

# custom filter
app.jinja_env.filters["usd"] = usd

# configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

@app.route("/")
@login_required
def index():
    final = dict()
    current_price_dict = dict()
    shares_list = list()
    total_current_value = 0
    user_id = session["user_id"]
    user_cash = db.execute("SELECT cash FROM users where id = :userid", userid=user_id)
    #user_portfolio = db.execute("SELECT * FROM portfolio where users_id = :usersid", usersid = user_id)
    users_shares = db.execute("SELECT share_name, SUM(share_quantity) FROM portfolio WHERE users_id = :usersid GROUP BY share_name", usersid=user_id)
    if user_cash != None and users_shares != None :
        for key in users_shares:
            for value in key :
                shares_list.append(key[value])
        for i in range(0, len(shares_list), 2) :
            price_dict = lookup(shares_list[i])
            stock_name = price_dict["name"]
            stock_symbol = price_dict["symbol"]
            current_price = float("{0:.2f}".format(price_dict["price"]))
            share_quantity = shares_list[i+1]
            total_val = float("{0:.2f}".format(current_price * share_quantity))
            total_current_value += float("{0:.2f}".format(total_val))
            current_price_dict[stock_symbol] = [stock_name, share_quantity, current_price, total_val]

        total_current_value += float("{0:.2f}".format(user_cash[0]["cash"]))
        final["balance"] = float("{0:.2f}".format(user_cash[0]["cash"]))
        final["stocks"] = current_price_dict
        final["total_value"] = float("{0:.2f}".format(total_current_value))


    return render_template("index.html", final=final)

@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock."""
    if request.method == "GET":
        return render_template("buy.html")
    elif request.method == "POST":
        shares = (int)(request.form.get("shares"))
        symbol = request.form.get("symbol")

        if shares == "" :
            return apology("Shares cannot be empty")
        elif (int)(shares) < 1 :
            return apology("Shares has to be a positive integer")
        elif symbol == "" :
            return apology("Symbol cannot be empty ")
        else :
            answer = lookup(request.form.get("symbol"))
            if answer == None :
                return apology("Ummmmm ... I don't know of any such symbol :(")
            else :
                shares = (int) (shares)
                share_price = float("{0:.2f}".format(answer["price"]))
                share_full_name = answer["name"]
                shares_cost = float("{0:.2f}".format(shares * share_price))

                my_query = db.execute("SELECT *  FROM users WHERE id = :id", id=session["user_id"])

                if my_query == None :
                    return apology("Sorry we were unable to query the database at this point, please try again later")
                else :
                    my_username = my_query[0]["username"]
                    my_cash = float("{0:.2f}".format(my_query[0]["cash"]))

                    remainder = float("{0:.2f}".format(my_cash - shares_cost))

                    if  my_cash >= shares_cost :
                        transaction = db.execute("INSERT INTO transactions ( user_name, share_name, share_quantity, share_price, total_cost, time, users_id, type, share_full_name) VALUES (:username, :symbol, :share_quantity, :share_price, :total_cost, :time, :users_id, :types, :share_full_name)", username=my_username, symbol=symbol, share_quantity=shares, share_price=share_price, total_cost=shares_cost, time=str(datetime.now()), users_id=session["user_id"], types="BUY", share_full_name=share_full_name)
                        update_u = db.execute("UPDATE users SET cash = :remainder where id = :id", remainder=remainder, id=session["user_id"])
                        update_p = db.execute("INSERT INTO portfolio ( user_name, share_name, share_quantity, share_price, total_cost, time, users_id) VALUES (:username, :symbol, :share_quantity, :share_price, :total_cost, :time, :users_id)", username=my_username, symbol=symbol, share_quantity=shares, share_price=share_price, total_cost=shares_cost, time=str(datetime.now()), users_id=session["user_id"])
                        return redirect(url_for("index"))

                    else :
                        return apology("You don't have enough funds")
    else :
        return apology("You can only use GET and POST methods here")

@app.route("/history")
@login_required
def history():
    """Show history of transactions."""
    show = db.execute("SELECT * FROM transactions WHERE users_id = :id", id=session["user_id"])
    return render_template("transactions.html", transactions=show)

@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in."""

    # forget any user_id
    session.clear()

    # if user reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username")

        # ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password")

        # query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username", username=request.form.get("username"))

        # ensure username exists and password is correct
        if len(rows) != 1 or not pwd_context.verify(request.form.get("password"), rows[0]["hash"]):
            return apology("invalid username and/or password")

        # remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # redirect user to home page
        return redirect(url_for("index"))

    # else if user reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")

@app.route("/logout")
def logout():
    """Log user out."""

    # forget any user_id
    session.clear()

    # redirect user to login form
    return redirect(url_for("login"))

@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    if request.method == "GET" :
        return render_template("quote.html")
    elif request.method == "POST":
        """Get stock quote."""
        answer = lookup(request.form.get("symbol"))
        if answer == None :
            return apology("Ummmmm ... I don't know of any such symbol :(")
        else :
            return render_template("quoted.html", answer=answer)


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user."""

    if request.method == "GET" :
        return render_template("register.html")
    elif request.method == "POST" :
        username = request.form.get("username")
        password = request.form.get("password")
        password_again = request.form.get("password_again")

        if username == "" :
            return apology("Username cannot be blank")
        elif password == "" or password_again == "":
            return apology("Password fields cannot be blank")
        elif password_again != password :
            return apology("Passwords do not match")

        password = pwd_context.hash(password)
        result = db.execute("INSERT INTO users (username,hash) VALUES (:username, :hash)", username = username, hash=password)

        if not result:
            return apology("Sorry, Username already exists")
        else :
            rows = db.execute("SELECT * FROM users WHERE username = :username", username=username)
            session["user_id"] = rows[0]["id"]
            return redirect(url_for("index"))

    else :
        return apology("You can only use GET and POST methods here")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock."""
    if request.method == "GET":
        return render_template("sell.html")
    elif request.method == "POST":
        shares = (int)(request.form.get("shares"))
        symbol = request.form.get("symbol")

        if shares == "" :
            return apology("Shares cannot be empty")
        elif (int)(shares) < 1 :
            return apology("Shares has to be a positive integer")
        elif symbol ==  "":
            return apology("Symbol cannot be empty")
        else :
            verify_trans = db.execute("SELECT SUM(share_quantity) FROM portfolio WHERE users_id = :usersid AND share_name = :symbol", usersid=session["user_id"], symbol=symbol)
            if verify_trans == None :
                return apology("O Noes ... Something is wrong with the database")
            else :
                cur_shares = verify_trans[0]['SUM(share_quantity)']
                if cur_shares == None:
                    return apology("You do not own any shares of {}".format(symbol))
                elif shares > cur_shares :
                    return apology("You have only {} shares for the share you are trying to sell".format(cur_shares))
                else :
                    answer = lookup(request.form.get("symbol"))
                    if answer == None :
                        return apology("Ummmmm ... I dont know of any such symbol :(")
                    else :
                        shares = (int) (shares)
                        share_price = answer["price"]
                        share_full_name = answer["name"]
                        shares_cost = float("{0:.2f}".format(shares * share_price))

                        my_query = db.execute("SELECT *  FROM users WHERE id = :id", id=session["user_id"])

                        if my_query == None :
                            return apology("Sorry we were unable to query the database at this point, please try again later")
                        else :
                            my_username = my_query[0]["username"]
                            my_cash = float("{0:.2f}".format(my_query[0]["cash"]))

                            remainder = float("{0:.2f}".format(my_cash + shares_cost))
                            transaction = db.execute("INSERT INTO transactions ( user_name, share_name, share_quantity, share_price, total_cost, time, users_id, type, share_full_name) VALUES (:username, :symbol, :share_quantity, :share_price, :total_cost, :time, :users_id, :types, :share_full_name)", username=my_username, symbol=symbol, share_quantity=shares, share_price=share_price, total_cost=shares_cost, time=str(datetime.now()), users_id=session["user_id"], types="SELL", share_full_name=share_full_name)

                            for i in range(shares):
                                update_u = db.execute("UPDATE users SET cash = :remainder where id = :id", remainder=remainder, id=session["user_id"])
                                get_max_time = db.execute("SELECT max(time) FROM portfolio WHERE users_id = :users_id AND share_name = :symbol", users_id=session["user_id"], symbol=symbol)
                                max_time = get_max_time[0]["max(time)"]
                                update_p = db.execute("DELETE FROM portfolio WHERE users_id = :users_id AND share_name = :symbol AND time = :max_time", users_id=session["user_id"], symbol=symbol, max_time=max_time)
                            return redirect(url_for("index"))

    else :
        return apology("You can only use GET and POST methods here")
