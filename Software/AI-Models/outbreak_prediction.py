import pandas as pd
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import train_test_split

# Load datasets
water = pd.read_csv('../../datasets/water-quality/water_quality_synthetic.csv')
health = pd.read_csv('../../datasets/health-reports/ecg_data.csv')

# Merge on timestamp
data = pd.merge(water, health, on='date')

X = data[['ph', 'tds', 'turbidity', 'fever_cases', 'diarrhea_cases']]
y = data['outbreak']

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

model = LogisticRegression()
model.fit(X_train, y_train)

print("Accuracy:", model.score(X_test, y_test))
