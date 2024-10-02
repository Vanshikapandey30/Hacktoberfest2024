# Organize Files by Extension Script

## Overview
This script automatically organizes files in the current directory into subfolders based on their file extensions. It creates a folder for each unique extension and moves the corresponding files into these folders.

## How It Works
1. **Set Directory**: The script sets the working directory to the location where the script is executed.
2. **Iterate Through Files**: It loops through all files in the directory.
3. **Extract Extension**: For each file, it extracts the file extension.
4. **Create Folders**: If a folder for the extension does not already exist, it creates one.
5. **Move Files**: The script moves each file into its respective folder based on its extension.

## Usage
1. Save the script as `organize_files.bat`.
2. Place the script in the directory containing the files you want to organize.
3. Double-click the script to execute it. All files will be sorted into folders according to their extensions.

## Requirements
- This script is designed for Windows environments.
- No additional software is required.

## Example
If your directory contains the following files:
- `document.txt`
- `image.jpg`
- `script.py`

After running the script, the directory will be organized as:
```
/text
    └── document.txt
/image
    └── image.jpg
/python
    └── script.py
```

## Notes
- The script will only create folders for extensions that are present in the directory.
- If a file does not have an extension, it will remain in the root directory.

Feel free to modify the script as needed to fit your organizational preferences!