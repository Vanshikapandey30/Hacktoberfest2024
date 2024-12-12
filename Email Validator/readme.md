# Email Checker

This script defines a function _isValidEmail_ that takes an email address as input and checks if it matches the regular expression pattern for a valid email address. The regular expression pattern used here is a simple one and may not cover all edge cases, but it should work for most common email formats.

You can modify the regular expression pattern to make it more or less strict based on your requirements.

## The Regex
The regular expression _pattern = r'^[\w\.-]+@[\w\.-]+\.\w+'_ is used to match email addresses in Python. Here's a breakdown of the different parts of the regular expression:

   #### ^: Matches the start of a string.
   #### [\w\.-]+: Matches one or more word characters (letters, digits, or underscores), dots, or hyphens.
   #### @: Matches the "@" symbol.
   #### [\w\.-]+: Matches one or more word characters, dots, or hyphens.
   #### \.: Matches a literal dot.
   #### \w+: Matches one or more word characters.

So, the regular expression matches strings that start with one or more word characters, dots, or hyphens, followed by an "@" symbol, followed by one or more word characters, dots, or hyphens, followed by a literal dot, and ending with one or more word characters. This pattern matches most email addresses, but it may not match all valid email addresses