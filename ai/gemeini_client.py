from google import genai
from ai.config import gemini_api_key

def get_chatgpt_response(request):
    client = genai.Client(api_key=gemini_api_key)
    response = client.models.generate_content(
        model="gemini-2.0-flash", contents=request
    )
    
    return response.text