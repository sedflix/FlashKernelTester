# Kernel/CFS-RT


## Usage 

My syscall number is:  323 

```
    syscall(323, <pid> , <x>);
```
It sets the running time of the process with pid <pid> to 750000ULL * <x> nanosecond.
Here `750000ULL` is the minimum possible time.

## Expected result

As soon as you call this syscall, the process with the given <pid>
will run for as long as time assigned to it is not over.
After that it will be scheduled like a normal process.

The given test.c can used to see the usage and to do testing.
The child process(whose rtnice value is modified) runs as long as it reaches 0 and after that is runs like a normal process

## Error Handling

- ESRCH |   3   |   If no with the given pid is found process
- If the process has exited, do not schedule it
- Do not schedule same process on more than one core 

## Implementation

See tha patch. It is proper comments.
I've modified cfs's rb_tree comparator, which is `entity_before`.


