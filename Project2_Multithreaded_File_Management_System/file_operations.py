import os
import shutil
import threading
import time
from datetime import datetime

class FileManager:
    def __init__(self):
        self.read_lock = threading.Lock()
        self.write_lock = threading.Lock()
        self.log_lock = threading.Lock()

    def read_file(self, filename):
        with self.read_lock:  # Allow multiple reads
            if os.path.exists(filename):
                with open(filename, 'r') as file:
                    data = file.read()
                    print(f"Read from {filename}: {data}")
            else:
                print(f"{filename} does not exist.")

    def write_file(self, filename, data):
        with self.write_lock:  # Ensure exclusive access for writing
            with open(filename, 'w') as file:
                file.write(data)
                print(f"Wrote to {filename}: {data}")

    def delete_file(self, filename):
        with self.write_lock:  # Ensure exclusive access for deletion
            if os.path.exists(filename):
                os.remove(filename)
                print(f"Deleted {filename}")
            else:
                print(f"{filename} does not exist.")

    def rename_file(self, old_name, new_name):
        with self.write_lock:  # Ensure exclusive access for renaming
            if os.path.exists(old_name):
                os.rename(old_name, new_name)
                print(f"Renamed {old_name} to {new_name}")
            else:
                print(f"{old_name} does not exist.")

    def copy_file(self, src, dest):
        with self.write_lock:  # Ensure exclusive access for copying
            if os.path.exists(src):
                shutil.copy(src, dest)
                print(f"Copied from {src} to {dest}")
            else:
                print(f"{src} does not exist.")

    def display_metadata(self, filename):
        if os.path.exists(filename):
            stat_info = os.stat(filename)
            print(f"Metadata for {filename}:")
            print(f"Size: {stat_info.st_size} bytes")
            print(f"Created: {datetime.fromtimestamp(stat_info.st_ctime)}")
            print(f"Modified: {datetime.fromtimestamp(stat_info.st_mtime)}")
            print(f"Permissions: {oct(stat_info.st_mode)}")
        else:
            print(f"{filename} does not exist.")