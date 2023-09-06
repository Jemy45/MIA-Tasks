import pandas as pd
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error

# Load the dataset
data = pd.read_csv('shrink_ray_dataset.csv')

# Separate the features (X) and target variable (y)
X = data[['knob_setting']]
y = data['shrinkage']

# Split the data into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Create a linear regression model
model = LinearRegression()

# Train the model on the training data
model.fit(X_train, y_train)

# Make predictions on the test data
y_pred = model.predict(X_test)

# Calculate Mean Squared Error
mse = mean_squared_error(y_test, y_pred)
print('Mean Squared Error:', mse)

# Plot the predicted values vs. actual values
plt.scatter(y_test, y_pred)
plt.xlabel('Actual Shrinkage')
plt.ylabel('Predicted Shrinkage')
plt.title('Predicted vs. Actual Shrinkage')
plt.show()
