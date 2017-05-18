# compiles brain-flak to C

$boiler_plate = File.read "boilerplate.h"

$header = File.read "header.h"

$cmds = {
    '('  => "stack_push(workspace, current_sum); current_sum = 0;",
    ')'  => "stack_push(*current_stack, current_sum); current_sum += stack_pop(workspace);",
    '()' => "current_sum++;",
    
    '{'  => "while(stack_peek(*current_stack) != 0){",
    '}'  => "}",
    '{}' => "current_sum += stack_pop(*current_stack);",
    
    '['  => "stack_push(workspace, current_sum); current_sum = 0;",
    ']'  => "current_sum = -current_sum; current_sum += stack_pop(workspace);",
    '[]' => "current_sum += (*current_stack)->size;",
    
    '<'  => "stack_push(workspace, current_sum); current_sum = 0;",
    '>'  => "current_sum = 0; current_sum += stack_pop(workspace);",
    '<>' => "
if(pointed_stack == AT_FIRST){
    printf(\"switching to second\\n\");
    current_stack = &second_stack;
    pointed_stack = AT_SECOND;
} else {
    printf(\"switching to first\\n\");
    current_stack = &first_stack;
    pointed_stack = AT_FIRST;
}
"[1..-1],
}

def all_tokens
    $cmds.keys.sort { |a, b| -(a.size <=> b.size) }
end

def compile(str)
    reg = Regexp.new all_tokens.map { |e| Regexp.escape e }.join "|"
    toks = str.scan(reg)
    toks.map { |e| "// #{e}\n#{$cmds[e]}" } .join "\n"
end

file_name = ARGV[0]

program = File.read(file_name)

comp = compile(program)

result = "#{$boiler_plate}
int main(){
#{$header}
#{comp}
stack_display(*current_stack);
}"

out_file = File.open "_result.c", "w"
out_file.write result
out_file.close

system("gcc -Wall _result.c -o bf")