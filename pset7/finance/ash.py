#!/usr/bin/env python3

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session, url_for
from flask_session import Session
from passlib.apps import custom_app_context as pwd_context
from tempfile import mkdtemp

from helpers import *

db = SQL("sqlite:///finance.db")
counter = 0
shares_list = list()
final = dict()
current_price_dict = dict()
user_id = 1
symbol = "sadf"

show = db.execute("SELECT * FROM transactions WHERE users_id = :id", id=1)
for i in show:
    print (i['id'])






"""users_shares = db.execute("SELECT share_name, SUM(share_quantity) FROM portfolio WHERE users_id = :usersid GROUP BY share_name", usersid=user_id)
if users_shares != None :
 for key in users_shares:
     for value in key :
         shares_list.append(key[value])
 for i in range(0, len(shares_list), 2) :
     price_dict = lookup(shares_list[i])
     stock_name = price_dict["name"]
     stock_symbol = price_dict["symbol"]
     current_price = price_dict["price"]
     share_quantity = shares_list[i+1]
     total_val = current_price * share_quantity
     current_price_dict[stock_symbol] = [stock_name, current_price, share_quantity, total_val]

 final["cash"] = "100"
 final["stocks"] = current_price_dict

for stock in final["stocks"]:
    print(final["stocks"][stock])

a_dict = dict()
b_dict = dict()
a_dict["ash"] = [1,2,3,4]
b_dict["stock"] = ["goog", "google", 100]
b_dict["stock_a"] = ["nflx", "netflix", 200]
a_dict["bash"] = b_dict
print(a_dict)"""
