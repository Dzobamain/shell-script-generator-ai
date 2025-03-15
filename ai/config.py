import os
from dotenv import load_dotenv

load_dotenv()

gemini_api_key = os.getenv("GIMINEI_API_KEY")
if not gemini_api_key:
    raise ValueError("API key not found! Please check your .env file.")

