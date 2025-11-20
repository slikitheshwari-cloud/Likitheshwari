import random

def generate_pattern(length=20, max_repeat=4):
    
    pattern = ""
    prev_char = ""
    repeat_count = 0

    for _ in range(length):
        options = ['a', 'b', 'c', 'd']

        # If previous char repeated max_repeat times, remove it from options
        if repeat_count >= max_repeat:
            options.remove(prev_char)

        # Randomly choose next character
        char = random.choice(options)
        pattern += char

        # Update repeat count
        if char == prev_char:
            repeat_count += 1
        else:
            prev_char = char
            repeat_count = 1

    return pattern

def generate_patterns(count=200, length=20, max_repeat=4):
    """
    Generate a set of unique patterns.
    """
    patterns = set()
    while len(patterns) < count:
        patterns.add(generate_pattern(length, max_repeat))
    return list(patterns)

# Generate 200 patterns
patterns = generate_patterns(count=200)

# Print the patterns
for i, p in enumerate(patterns, 1):
    print(f"{i}. {p}")
