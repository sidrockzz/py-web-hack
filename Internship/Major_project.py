
import numpy as np
import pandas as pd
from sklearn.preprocessing import LabelEncoder, OneHotEncoder

# Reading dataset >>
train_data = pd.read_excel("Data_Train (1).xlsx")
print(train_data, end='')

test_dataset = pd.read_excel("Data_Test (1).xlsx")
test_data=test_dataset[:]
print(test_data, end='')


# Dropping the unwanted columns >>
train_data = train_data.drop("Name", axis=1)
train_data = train_data.drop("New_Price", axis=1)
# For Test Data
test_data = test_data.drop("Name", axis=1)
test_data = test_data.drop("New_Price", axis=1)

print("\n<<<--- After Dropping Columns --->>>\n")
print(train_data, end='')

print("   ")
print(train_data.describe(include="all"), end='')


# Data Cleaning Using RegX >>
train_data['Mileage'].replace(regex=True, inplace=True, to_replace=r'[a-z]*[/][a-z]*', value=r'')
train_data['Mileage'].replace(regex=True, inplace=True, to_replace=r'[a-z]*', value=r'')
train_data['Mileage'].replace(regex=True, inplace=True, to_replace=r"[' ']*", value=r'')
train_data['Engine'].replace(regex=True, inplace=True, to_replace=r"[' ']['CC']*", value=r'')
train_data['Power'].replace(regex=True, inplace=True, to_replace=r"[' ']['bhp']*", value=r'')
# For Test Dataset
test_data['Mileage'].replace(regex=True, inplace=True, to_replace=r'[a-z]*[/][a-z]*', value=r'')
test_data['Mileage'].replace(regex=True, inplace=True, to_replace=r'[a-z]*', value=r'')
test_data['Mileage'].replace(regex=True, inplace=True, to_replace=r"[' ']*", value=r'')
test_data['Engine'].replace(regex=True, inplace=True, to_replace=r"[' ']['CC']*", value=r'')
test_data['Power'].replace(regex=True, inplace=True, to_replace=r"[' ']['bhp']*", value=r'')



# Taking Care of Missing values(NaN) >>
train_data['Mileage'].fillna(train_data['Mileage'].median(), inplace=True)
train_data['Engine'].fillna(train_data['Engine'].median(), inplace=True)
train_data['Seats'].fillna(train_data['Seats'].median(), inplace=True)
train_data['Power'].fillna(74.0, inplace=True)
# For Test Dataset
test_data['Mileage'].fillna(train_data['Mileage'].median(), inplace=True)
test_data['Engine'].fillna(train_data['Engine'].median(), inplace=True)
test_data['Seats'].fillna(train_data['Seats'].median(), inplace=True)
test_data['Power'].fillna(74.0, inplace=True)



# Taking Care of some null values and Filling it with most frequeent values >>
train_data['Power'].replace(regex=True, inplace=True, to_replace=r"['null']", value=74.0)
train_data['Engine'].replace(regex=True, inplace=True, to_replace=r"['null']", value=1346.0)
train_data['Mileage'].replace(regex=True, inplace=True, to_replace=r"['null']", value=21.5)
# For Test Dataset
test_data['Power'].replace(regex=True, inplace=True, to_replace=r"['null']", value=74.0)
test_data['Engine'].replace(regex=True, inplace=True, to_replace=r"['null']", value=1346.0)
test_data['Mileage'].replace(regex=True, inplace=True, to_replace=r"['null']", value=21.5)



# Data set after Cleaning and Filling nan and null values >>
X =train_data
print('\n<<<---Final dataset--->>>\n',X)
# For Test Dataset
X1 = test_data


# Feature Selection >>
labelencoder_X= LabelEncoder()

X['Location'] = labelencoder_X.fit_transform(X['Location'])
X['Year'] = labelencoder_X.fit_transform(X['Year'])
X['Fuel_Type'] = labelencoder_X.fit_transform(X['Fuel_Type'])
X['Transmission'] = labelencoder_X.fit_transform(X['Transmission'])
X['Owner_Type'] = labelencoder_X.fit_transform(X['Owner_Type'])
# For Test Dataset
X1['Location'] = labelencoder_X.fit_transform(X1['Location'])
X1['Year'] = labelencoder_X.fit_transform(X1['Year'])
X1['Fuel_Type'] = labelencoder_X.fit_transform(X1['Fuel_Type'])
X1['Transmission'] = labelencoder_X.fit_transform(X1['Transmission'])
X1['Owner_Type'] = labelencoder_X.fit_transform(X1['Owner_Type'])

ohe = OneHotEncoder(categorical_features=[0])
X = ohe.fit_transform(X).toarray()
X1 = ohe.fit_transform(X1).toarray()

ohe1 = OneHotEncoder(categorical_features=[13])
X = ohe1.fit_transform(X).toarray()
X1 = ohe1.transform(X1).toarray()

X = X[:, 0:24]
Y = train_data.iloc[:, -1].values

# Splitting in Train and Test >>
from sklearn.model_selection import train_test_split

X_train, X_test, Y_train, Y_test = train_test_split(X, Y.astype('int'), test_size=0.2, random_state=0)

# Fitting Polynomial Regression to Dataset >>
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import PolynomialFeatures

poly_reg = PolynomialFeatures(degree=3)
X_poly = poly_reg.fit_transform(X_train)
X_polytest = poly_reg.fit_transform(X_test)

lin_reg = LinearRegression()
lin_reg.fit(X_poly, Y_train)
Y_pred = lin_reg.predict(X_polytest)
# For Test Dataset
X1_poly = poly_reg.transform(X1)
Y1_pred = lin_reg.predict(X1_poly)

# Predicting r2 score >>
from sklearn.metrics import r2_score

scroe = r2_score(Y_test, Y_pred)
print('\nR2 score with 3 degree polynomial regression :>',scroe)

# Predicting root mean square >>
rms = np.sqrt(np.mean((Y_test - Y_pred) ** 2))
print("\nRoot Mean Square :>",rms)
# For Test Dataset
test_dataset["Price"] = Y1_pred

# Writing into xlsx >>
test_dataset.to_excel(r"./Predicted_Test_Data.xlsx")
print("\nSuccessful !! Predicted_Test_Data.xlsx file Created\n")

Capstone_Verzeo_major.py
Displaying Capstone_Verzeo_major.py.
