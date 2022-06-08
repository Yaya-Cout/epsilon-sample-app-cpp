#!/usr/bin/env python3
"""Inline the files in the assets directory into a single file."""
# Global imports
import os
# Initialize global variables
ASSETS_DIR = "assets"
OUTPUT_FILE = "target/assets.cpp"


def get_code(assets_dir: str) -> list[str]:
    """Inline the files in the given directory into a list of C++ code.

    Args:
        assets_dir (str): The directory that contain the assets

    Returns:
        str: The list of C++ code
    """
    # Initialise the list of code
    list_of_code: list[str] = []
    # Initialise the list of files
    list_of_files: list[list[str]] = []
    # Set the type of file_name
    file_name: str
    # Iterate over the files
    for file_name in os.listdir(assets_dir):
        # Get if the file is a directory
        is_dir: bool = os.path.isdir(os.path.join(assets_dir, file_name))
        # If it is a directory, recursively inline the files
        if is_dir:
            list_of_code.extend(get_code(os.path.join(assets_dir,
                                                      file_name)))
        # If it is a file, inline it
        else:
            file_name_mod: str = file_name.replace(".", "_")
            file_name_mod = "file_" + file_name_mod
            list_of_files.append([file_name, file_name_mod])
            file: str = ""
            file += "const uint8_t " + file_name_mod + "[] = {\n"
            # Add each byte of the file
            with open(os.path.join(assets_dir, file_name), "rb") as f:
                for byte in f.read():
                    file += str(byte) + ", "
            file += "};\n"
            list_of_code.append(file)
    # Add the list of files to the list of code
    list_of_code.append("const char* files[] = {\n")
    file_name_list: list[str]
    for file_name_list in list_of_files:
        list_of_code.append("    \"" + file_name_list[0] + "\",\n")
    list_of_code.append("};\n")
    # Add the list of assets to the list of code
    list_of_code.append("const uint8_t* assets[] = {\n")
    for file_name_list in list_of_files:
        list_of_code.append("    " + file_name_list[1] + ",\n")
    list_of_code.append("};\n")
    # Return the list of code
    return list_of_code


def inline_code(list_of_code: list[str]) -> str:
    """Convert a list of code to a single C++ file.

    Args:
        list_of_code (list[str]): The list of C++ code

    Returns:
        str: The file as a string
    """
    # Initialize the string
    code = ""
    # Add the header
    code += "#include <stdint.h>\n\n"
    # Add each code
    for code_part in list_of_code:
        code += code_part
    # Return the code
    return code


def main():
    """Run the program."""
    # Get the code
    list_of_code = get_code(ASSETS_DIR)
    # Inline the code
    code = inline_code(list_of_code)
    # Write the code to the output file
    with open(OUTPUT_FILE, "w", encoding="utf-8") as f:
        f.write(code)


if __name__ == "__main__":
    main()
