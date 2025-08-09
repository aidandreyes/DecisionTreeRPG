This is a text-based RPG game in C++ that uses decision trees represented as binary trees. 
Each decision will lead the player through different game outcomes, where each event can lead to two possible outcomes, except for one special case where multiple events can converge to the same outcome.
Story data is imported from the story text file.
Each line in the file will contain event descriptions, numbers, and pointers to two outcomes (left or right), separated by a " | " delimiter. 
