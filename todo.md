### Error handling
- no duplicate numbers in the input
- no integers as input
- args bigger than int
	t_stack c;
	int i;
	int j;
	int last_number;
	int current_number;
	int current_index;

	// c = a;
	i = 0;
	// // while (i < a.count)
	// // {
	// // 	j = 0;
	// // 	while (j < a.count)
	// // 	{
			
	// // 		if(a.numbers[a.index + j] < current_number && a.numbers[a.index + j] > last_number)
	// // 		{
	// // 			current_number = a.numbers[a.index + i];
	// // 			current_index = i;
	// // 		}
	// // 		j++;
	// // 	}
	// // 	last_number = current_number;
	// // 	c.numbers[c.index + current_index] = i;
	// // 	i++;
	// // }

	// // Search for smallest number
	j = 0;
	current_number = a.numbers[a.index];
	while (i < a.count)
	{
		if (a.numbers[a.index + i] < current_number)
		{
			current_number = a.numbers[a.index + i];		
			current_index = i;
		}
		i++;
	}
	c.numbers[c.index + current_index] = j++;
	last_number = current_number;
	printf("Last number: %i\n",last_number);
	while (j < a.count)
	{
		i = 0;
		current_number = 2147483647;
		while (i < a.count)
		{
			if (a.numbers[a.index + i] < current_number && a.numbers[a.index +i] > last_number)
			{
				current_number = a.numbers[a.index + i];
				current_index = i;
			}
			i++;
		}
		last_number = current_number;
		c.numbers[c.index + current_index] = j;
		j++;
	}