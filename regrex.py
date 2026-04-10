import re
text = "My phone number is 9876543210"
pattern = r'\d{10}'
match = re.search(pattern, text)
if match:
    print("Found:", match.group())