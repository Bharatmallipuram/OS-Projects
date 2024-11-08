import logging
from datetime import datetime  # Import datetime here

logging.basicConfig(filename='file_operations.log', level=logging.INFO)

def log_operation(operation, filename):
    logging.info(f"{operation} on {filename} at {datetime.now()}")