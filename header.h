stack* workspace = malloc(sizeof(stack));
stack* first_stack = malloc(sizeof(stack));
stack* second_stack = malloc(sizeof(stack));
stack** current_stack = &first_stack;
long current_sum;
stack_init(workspace, 16);
stack_init(second_stack, 16);
stack_init(first_stack, 16);
current_sum = 0;