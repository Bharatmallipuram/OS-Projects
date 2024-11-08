import threading
import time
from file_operations import FileManager
from logger import log_operation

def perform_operations(file_manager):
    # Example operations
    file_manager.write_file('example.txt', 'Hello World!')
    log_operation('Write', 'example.txt')

    time.sleep(1)  # Simulate some delay

    file_manager.read_file('example.txt')
    log_operation('Read', 'example.txt')

    file_manager.rename_file('example.txt', 'example_renamed.txt')
    log_operation('Rename', 'example.txt')

    file_manager.display_metadata('example_renamed.txt')

    file_manager.copy_file('example_renamed.txt', 'example_copy.txt')
    log_operation('Copy', 'example_renamed.txt')

    file_manager.delete_file('example_copy.txt')
    log_operation('Delete', 'example_copy.txt')

if __name__ == "__main__":
    file_manager = FileManager()
    
    threads = []
    for i in range(5):  # Creating multiple threads for demonstration
        thread = threading.Thread(target=perform_operations, args=(file_manager,))
        threads.append(thread)
        thread.start()

    for thread in threads:
        thread.join()