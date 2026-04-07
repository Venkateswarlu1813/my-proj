import os

def list_files():
    try:
        return os.listdir()
    except Exception as e:
        return str(e)

def create_folder(name):
    try:
        os.mkdir(name)
        return "Folder created"
    except FileExistsError:
        return "Folder already exists"