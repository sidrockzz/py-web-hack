from flask import Flask, render_template, request
#imports date time
import datetime
#app variable represents this is the current __name__ web application stored
app = Flask(__name__)
#route is part of url where we want to go.Under the route if we write any function we it will execute that function
@app.route("/")
def index():
 return render_template("index.html")
#submitting the data to hello function for POST whereas GET is for getting the data
@app.route("/hello", methods=['GET', 'POST'])
def hello():
 if request.method == "GET":
  return "<h1>Please submit the form instead</h1>"
 else:
  name = request.form.get("name")
  return render_template("hello.html",name=name)
