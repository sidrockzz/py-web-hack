from flask import Flask, render_template
#imports date time
import datetime
#app variable represents this is the current __name__ web application stored
app = Flask(__name__)
#route is part of url where we want to go.Under the route if we write any function we it will execute that function
@app.route("/")
def index():
#web app regarding whether it is new year or not
 now = datetime.datetime.now()
 new_year = now.month == 1 and now.day == 1
 return render_template("index.html",new_year=new_year,now=now)
