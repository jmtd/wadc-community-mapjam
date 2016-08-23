/*
 * vim: set ft=wadc:
 *
 * Jon's WadC mapjam room, first attempt
 */

jon_boring {
    -- literally a box. boring!
    box(get("floor"), add(get("floor"), 190), 160, 512, 512)

    -- exit door will be in the top-most wall
    -- position the cursor on that edge. No need to rotate.
    movestep(512)
}
