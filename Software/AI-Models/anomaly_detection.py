import pandas as pd
from sklearn.ensemble import IsolationForest

# Load dataset
data = pd.read_csv('../../datasets/water-quality/water_quality_synthetic.csv')
features = data[['ph', 'tds', 'turbidity']]

# Train simple anomaly detection
model = IsolationForest(contamination=0.1, random_state=42)
model.fit(features)

data['risk'] = model.predict(features)
data['risk'] = data['risk'].map({1: 'Normal', -1: 'Contamination Risk'})

print(data.head())
