# Brain-Flak compiler

This is an implementation of the [Brain-Flak](https://github.com/DJMcMayhem/Brain-Flak) language, by way of compiling Brain-Flak to C. The compiler is written in Ruby so that it may be easily extensible.

## Important differences

1. Remember, this is very much a work in progress, thus, unexpected functionality may be obtained when running programs.
2. The compiler uses `long`s instead of arbitrary-precision integers, to favor speed and a smaller compiled result.

## Running

    $ bf2c.rb [infile]
    
    $ bf
    [result]

## Limitations

1. No flag support, currently.
2. No custom compile target.