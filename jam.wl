#"basic.h"
#"jon.h"


main {

    seed(1337)
    -- put a player 1 start in the first room, whatever that is
    place(64,64, thing)

    -- starting floor height: 0
    set("floor", 0)

    /*
     * Rooms! Each room must take up no more than 512x512 units.
     * When the room function is called, the pen will be positioned
     * at the bottom-right of the 512x512 space. You draw upwards
       and rightwards
     * There will be an entrance placed in the middle of this bottom
       space, 128 wide, in the middle (so: 192 units either side)
     * you should provide an exit somewhere on another edge of your
       512x512 space, and make sure that the cursor is positioned on
       that side when you're finished, in the corner. Example:

        +---------+>    Your box. The cursor will be at '0' when your
        |         |     your function starts; you should expect there
        |         E     to be a doorway into your box at XXX. You've decided
        |         |     to put your exit at E. You must position the cursor
        0---XXX---+     at > (facing right) when you're done.

     */

     jon_boring
     doorway

}
doorway {
    /*
     * a boring, featureless doorway, to join rooms together.
     * 64 deep so rooms start aligned to the 64x64 grid.
     */
    !doorway
    movestep(0,192)
    bigdoor(0,96,160)
}

bigdoor(f,c,l) {
  !bigdoor
  top("BIGDOOR1")
  move(24)

  linetype(1,0)

  right(128)
  movestep(0,-16) turnaround
  straight(128)
  unpegged
  movestep(0,-16) rotright
  linetype(0,0)
  mid("DOORTRAK")
  ceil("FLAT23")
  room(f,f,l,16,128)
  ^bigdoor

  room(f,c,l,24,128)
  move(16)
  room(f,c,l,24,128)
}
room(f,c,l,x,y) {
  movestep(x,y) turnaround
  box(f,c,l,x,y)
  movestep(0,y) turnaround
}


