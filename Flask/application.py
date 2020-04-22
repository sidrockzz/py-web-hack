from flask import Flask, render_template
#app variable represents this is the current __name__ web application stored
app = Flask(__name__)
#route is part of url where we want to go.Under the route if we write any function we it will execute that function
@app.route("/")
def index():
#renders the html page from the template
 return render_template("index.html")
