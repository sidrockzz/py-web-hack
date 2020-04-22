from flask import Flask, render_template, request, session
from flask_session.__init__ import Session
#app variable represents this is the current __name__ web application stored
app = Flask(__name__)
#route is part of url where we want to go.Under the route if we write any function we it will execute that function
app.config["SESSION_PERMANENT"]= False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)
#note taking applications
notes =[]
#to particular session added session["notes"]
@app.route("/", methods=['GET', 'POST'])
def index():
 if session.get("notes") is None:
  session['notes'] = []
 if request.method == "POST":
  note = request.form.get("note")
  session["notes"].append(note)
 

 return render_template("index.html",notes=session["notes"])
