from google import genai
from google.genai import types
from ai.ai_config import gemini_api_key, gemini_model, gemini_instruct

def get_gemini_response(request):
    client = genai.Client(api_key=gemini_api_key)
    response = client.models.generate_content(
        model=gemini_model,
        config=types.GenerateContentConfig(
            system_instruction=gemini_instruct),
        contents=request)
    
    return response.text