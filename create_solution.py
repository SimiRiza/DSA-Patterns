import os
import re
from openai import OpenAI

# ---------------- CONFIG ----------------
BASE_DIR = "."

CPP_HEADER = """#include <bits/stdc++.h>
using namespace std;

"""

client = OpenAI()  # uses OPENAI_API_KEY from environment

# ---------------- INPUTS ----------------
lc_number = input("Enter LeetCode problem number: ").strip()
pattern = input("Enter pattern folder name: ").strip()

print("\nPaste the LeetCode C++ code (end with an empty line):")
lines = []
while True:
    line = input()
    if line == "":
        break
    lines.append(line)

solution_code = "\n".join(lines)

# ---------------- EXTRACT METHOD NAME ----------------
match = re.search(r'\b(\w+)\s*\(', solution_code)
if not match:
    raise ValueError("Could not detect method name")

method_name = match.group(1)

# ---------------- AI PROMPT (MAIN ONLY) ----------------
prompt = f"""
Given the following LeetCode C++ solution:

{solution_code}

Generate a simple C++ main() function with 1–2 sample test cases
ONLY for local testing.

Do not modify the solution code.
Return ONLY the main() function.
"""

response = client.responses.create(
    model="gpt-4.1-mini",
    input=prompt,
    temperature=0.2
)

main_function = response.output_text

# ---------------- FILE PATH ----------------
folder_path = os.path.join(BASE_DIR, pattern)
os.makedirs(folder_path, exist_ok=True)

file_name = f"{lc_number}_{method_name}.cpp"
file_path = os.path.join(folder_path, file_name)

# ---------------- WRITE FILE ----------------
with open(file_path, "w") as f:
    f.write(CPP_HEADER)
    f.write(solution_code)
    f.write("\n\n")
    f.write(main_function)

print(f"\n✅ V2 file created with AI-generated main():\n{file_path}")
