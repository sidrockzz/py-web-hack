from flask import Flask, render_template
#imports date time
import datetime
#app variable represents this is the current __name__ web application stored
app = Flask(__name__)
#route is part of url where we want to go.Under the route if we write any function we it will execute that function
@app.route("/")
def index():
 return render_template("index.html")

@app.route("/more")
def more():
 return render_template("more.html")
