Total: ______________/68

Bonus: ______________/10

General: __/4

//___ Program includes a Makefile

//___ Program compiles and runs

//___ Program displays initial board

//___ Dice rolls are randomized

Starting New Game: __/2

//___ All players start on OSAP square

//___ All players start with $1500 and no properties

Command Line Arguments: __/3

//___ -testing: player can specify the two dice which are rolled

//___ -load filename: filename is a load file as described in the specifications.
       Using this command, starts a game based on this file

//___ Arguments can be be given in any order

THE FOLLOWING WILL NOT BE MARKED IF A LOAD FILE CANNOT BE READ AS A COMMAND LINE
ARGUMENT
__________________________________________________________________________________

Starting Load Game: __/3

//___ All players start on square given in file

//___ All players start with properties given in file

//___ Player that starts in Tims must leave Tims through valid means

Turn: __/7

//___ Rolls dice, numbers printed to screen

//___ Player is given opportunity to buy unowned property they land on

//___ Player plays tuition when landing on a square owned by another player

//___ Quit command to end game

//___ Save command to save details of current game to a file

//___ Cannot end turn (next) if player is eligible to roll

//___ Assets command for printing player stats to the screen (what is printed
will vary, should include money and properties as a minimum)


Trading: __/8

//___ Player can propose a trade to any other player

//___ Player can offer money for trade

//___ Player can offer property for trade

//___ Player can request money for trade

//___ Player can request property for trade

//___ Proposed trade can be accepted and rejected

//___ Player cannot trade property with improvements

//___ Player cannot trade property if a property in its monopoly has improvements

Improvements: __/3

//___ Player can buy improvements if monopoly is owned on a property which is not
a residence or a gym

//___ Player can sell improvements for half of their cost

//___ Player cannot buy improvements on residences and gyms

Monopolies: __/4

//___ Tuition is doubled if monopoly is owned and property has no improvements
(not residence/gym)

//___ Tuition is accurate for multiple residences being owned

//___ Tuition is accurate for multiple gyms being owned

//___ Tuition is accurate when property has improvements



Player Movement: __/6

(There should only ever be one token per player on the board regardless of movement type.)

//___ Player is moved on board through dice roll

//___ Player is moved on board through SLC Square

//___ Player is moved on board through Go to Tims Square

//___ Player is moved on board through Go to Tims in SLC card

//___ Player rolls again when doubles are rolled

//___ Player is moved to Tims after rolling 3 double in a row and does not first move to the
square the roll would land them on

Mortgages: __/3

//___ Player can mortgage property for half of its value

//___ Player can unmortgage property for mortgage value plus 10% on loan amount

//___ Player cannot mortgage property if a property in the monopoly has a improvement

Tims Line: __/5

//___ If player lands on Tims Line through rolling, they can leave on next turn

(You will likely have to look at code for DC Tims cup unless the student has implemented
loading with a Tim's cup)

//___ Player can leave Tims through Tims cup, money or rolling doubles

//___ Player must use a Tims cup or pay on third turn if they did not roll doubles (uses final
roll)

___ Tims Cup returned if used

//___ Max of 4 Tims Cups at a time

SLC/Needles Hall: __/3

//___ When SLC is landed on, movement occurs correctly and is random (may need to check code)

//___ When Needles Hall is landed on, money change follows given probabilities (may need to check code)

//___ Tims Cup is given 1% of the time instead of other actions (may need to check code)

Non-Ownable Squares: __/5

//___ Goose Nesting: Nothing happens on Goose Nesting

//___ Tuition Square: Player chooses to pay 10% of net worth or $300

//___ Coop Fee: Player pays $150 dollars

//___ Collect OSAP: Player gains $200 when they land on OSAP

//___ Collect OSAP: Player gains $200 when they pass over OSAP

Auctions: __/4

//___ An auction begins when a player declines buying a property

//___ An auction for each property occurs when a player goes bankrupt to the bank

//___ An auction continues until all except one player has withdrawn

//___ A player cannot successfully underbid another player in an auction

Bankrupt: __/3

___ Player give assets to a player if they go bankrupt to a player

___ Player receiving properties must pay 10% of the mortgage value of each mortgaged property
(may pay to unmortgage as well)

___ If a player does not unmortgage a property they receive through bankruptcy immediately,
they must pay 10% again to unmortgage it later 

Ending the Game: __/5

//___ Game continues until only one player is remaining

___ Program leaks no more than a modest amount of memory (aside from C++ libraries)

___ Program leaks no memory

__/2 No segfaults throughout entire demo (even if accidental invalid input)
    (-1 mark for each segfault)

Bonus: (Note to marker: please be descriptive and indicate level of difficulty. Difficulty numbers should be filled once the group has left to avoid arguments. 1 - easy and 10 - very difficult):
