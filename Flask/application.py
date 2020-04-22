from flask import Flask,
#app variable represents this is the current __name__ web application stored
app = Flask(__name__)
#route is part of url where we want to go.Under the route if we write any function we it will execute that function
@app.route("/")
def index():
 return "Hello World!!"
#creates our own hello with the given name on the link
@app.route("/<string:name>")
def hello(name):
 name = name.capitalize()
#can add html tags
 return f"<h1>Hello, {name}!</h1>"
