import os
from dotenv import load_dotenv

load_dotenv()

def read_from_file(file_path):
    with open(file_path, "r", encoding="utf-8") as chat_file:
        return chat_file.read()

gemini_instruct_file_path = "ai/gemini_instruct.txt"
gemini_instruct=read_from_file(gemini_instruct_file_path)
gemini_model = "gemini-2.0-flash"
gemini_api_key = os.getenv("GIMINI_API_KEY")

if not gemini_api_key:
    raise ValueError("API key not found! Please check your .env file.")