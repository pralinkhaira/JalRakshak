# JalRakshak: Smart Community Health Monitoring & Early Warning System

## Overview
JalRakshak (जलरक्षक) is an **AI-powered health monitoring and early warning system** that predicts and detects **water-borne disease risks** in rural communities of Northeast India. It combines **IoT-based hardware sensors** (pH, TDS, Turbidity) with **AI models trained on synthetic datasets** to forecast water contamination levels and provide **Water Quality Index (WQI) predictions**.

This project is an **extension of the earlier Vitals Monitoring System**, where ECG and Oximeter readings were tested with high accuracy. The experience with vitals anomaly detection has been adapted here to environmental health monitoring.

## Problem Statement
Rural areas in Northeast India face challenges from **unsafe drinking water** and **poor sanitation**, leading to frequent outbreaks of cholera, diarrhea, and typhoid. Traditional water quality testing is slow, expensive, and inaccessible. JalRakshak provides **real-time, low-cost, AI-driven insights** to prevent such outbreaks.

## Objectives
- Monitor **real-time water parameters**: pH, TDS, Turbidity (via hardware sensors).
- Train AI models on **synthetic water datasets** with 10+ features (DO, BOD, COD, nitrate, phosphate, fecal coliform, etc.).
- Predict **Water Quality Index (WQI)** and classify risk levels.
- Extend proven vitals monitoring methods into water-borne disease prevention.

## Correlation & Workflow

### 1. Data Sources
- **Hardware (IoT sensors):** pH, TDS, Turbidity readings from ESP32/Arduino.
- **Synthetic Dataset:** `water_quality_synthetic.csv` & `water_quality_synthetic.xlsx` with lab-like indicators.

➡ **Correlation:** Hardware gives live values, dataset enriches AI model with broader features.

### 2. AI Models (`water_quality_prediction.py`)
- **Random Forest (RF):** Baseline, good for small sensor inputs.
- **XGBoost:** Higher accuracy if available.
- **LSTM:** Forecasts seasonal water trends.

➡ **Plan:** Train on dataset → Test on hardware → Predict WQI → Classify risk.

### 3. Execution Plan
- **Train Model:** Run `water_quality_prediction.py` on synthetic dataset.
- **Save Model:** Export trained model as `model.pkl`.
- **Integrate Hardware:** ESP32 sends [pH, TDS, Turbidity].
- **AI Prediction:** Feed readings → Model → Predict WQI & contamination risk.
- **Risk Mapping:**
  - WQI > 80 → ✅ Safe  
  - 50 ≤ WQI ≤ 80 → ⚠️ Moderate risk  
  - WQI < 50 → ❌ High risk  

### 4. Validation
- Compare **hardware-only predictions** with **dataset-trained predictions**.
- Adjust feature importance (e.g., turbidity & fecal coliform as strong indicators).

### 5. Vitals Monitoring Connection
- Vitals Monitoring: ECG, SpO₂ → anomaly detection.
- AI Health Monitoring: pH, TDS, Turbidity → anomaly detection + WQI.

✅ Same AI pipeline: **collect → preprocess → predict → classify risk**.

## Schematics
- Visit [here](https://pralinkhaira.github.io/Storage-Misc/w_q_schematics.html)

## 📂 Repository Structure
```
pralinkhaira-jalrakshak/
│
├── README.md
├── LICENSE
│
├── hardware/
│   ├── ph_sensor/
│   │   └── ph_sensor.ino
│   ├── turbidity_sensor/
│   │   └── turbidity_sensor.ino
│   ├── tds_sensor/
│   │   └── tds_sensor.ino
│   └── esp32_integration/
│       └── water_monitoring.ino
│
├── vitals-monitoring/
│   ├── ecg2/
│   │   └── ecg2.ino
│   └── oximeter_glucometer_bp/
│       └── oximeter_glucometer_bp.ino
│
├── software/
│   └── ai-models/
│       ├── water_quality_prediction.py
│       ├── anomaly_detection.py
│       └── outbreak_prediction.py
│
├── datasets/
│   ├── water-quality/
│   │   ├── water_quality_synthetic.csv
│   │   └── water_quality_synthetic.xlsx
│   └── health-reports/
│       └── ecg_data.csv
│       └── ecg_data.xlxs
```

## Documentation
- **water_quality_prediction.py** – Main AI model script with RF, XGBoost, LSTM.
- **Synthetic Datasets** – CSV & XLSX with extended water quality features.
- **Hardware Codes** – Arduino/ESP32 scripts for real-time water monitoring.
- **Vitals Monitoring** – ECG and Oximeter codes for legacy validation.

---
✨ *JalRakshak: From Vitals Monitoring to Water Quality Prediction – safeguarding communities, one drop at a time.*
