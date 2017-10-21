![Travis CI Status](https://travis-ci.org/lxwagn/impossible-triangle.svg?branch=master)

# Impossible Triangle

Impossible Triangle is a fun portfolio project written in C by 
Lucas Wagner (lxwagn at gmail.com) based on a real-world toy,
the Cracker Barrel "Peg Game".

## What is the Impossible Triangle?

The American restaurant *Cracker Barrel* is famous for leaving a 
toy on the tables of restaurant patrons so that the patrons have 
something to occupy their time while waiting for their food
to arrive. The restaurant calls this toy the "Peg Game".

http://shop.crackerbarrel.com/toys-games/games/travel-games/peg-game/606154

The Peg Game burns through idle time easily, as the success or failure of 
each round cannot be known until the full round is played through to 
completion. This leads some frustrated patrons to claim that the 
triangle-shaped game is, indeed, thoroughly impossible.

The rules of the game are very much like the game of Checkers:

1. All holes except one (the "void") should be filled with a peg.
2. The location of the beginning "void" is left up to you.
3. Pegs do a Checkers-like "jump" over a neighboring peg.
4. When one peg jumps over one peg, the peg that is jumped is removed.
5. Play continues until only one peg remains.

This program generates the winning coordinates required to solve the 
Cracker Barrel Peg Game. It then provides the winning coordinates 
which could then be replicated on a real Peg Game toy.

## How Does It Work?

The winning strategy involves selecting a correct starting void. There 
are certain starting voids that guarantee a losing round. The program
simulates not knowing which voids these are, so it begins by selecting 
a pseudo-random starting void.

After a starting void is selected, the board is analyzed to detect all
possible legal moves, selecting one legal move at random. This process
continues until there are no legal moves. Without legal moves, the attempt
is forfeited and the program begins again.

If there is one peg remaining, the user has won and the winning moves
are displayed in an [x,y] format. Here are the coordinates for the 
default four level game board:

                              (0,0)
                         (1,0)     (1,1)
                    (2,0)     (2,1)     (2,2)
               (3,0)     (3,1)     (3,2)     (3,3)

## Technical Information

- The code is commented and formatted in K&R style
- Compiled using -Wall
- Tests are provided; written using CUnit 
- Uses straight ANSI/ISO C (C89)
- Compiles under both Red Hat Enterprise Linux and OpenBSD

## Known Issues 

#### Larger Board Sizes = Larger Wait Times
The puzzle tends to be logarithmic in its processor usage. Having a slightly 
A larger BOARD_SIZE can require substantially more time to complete a round. 
The default BOARD_SIZE of four ensures that the code stays true to the original
spirit of the game and that it completes a round in a reasonable length of time.

#### "Cannot Find A Starting Point"
For larger boards, the program may throw an error for not being 
able to find a starting point. This is by design. The program is given a 
finite amount of tries to find a starting point and the numbers generated
as coordinates for those tries are pseudo-random. Simply run the program
again or, if still unsuccessful, change the board size to a smaller size 
and recompile.

## Quick Start

#### Prerequisites
To compile the executable and tests, you need CUnit. For example, on Ubuntu:

    sudo apt install libcunit1 libcunit1-dev

#### Building (Executable + Tests)

    make && make test

#### Building (Executable Only)
To build the executable without tests:

    make 

#### Cleaning
To remove the executables and tests (if applicable):

    make clean
