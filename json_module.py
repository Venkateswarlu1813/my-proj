import json

def write_json(data):
    try:
        with open("data.json", "w") as f:
            json.dump(data, f)
        return "Data written"
    except Exception as e:
        return str(e)

def read_json():
    try:
        with open("data.json", "r") as f:
            return json.load(f)
    except FileNotFoundError:
        return "File not found"