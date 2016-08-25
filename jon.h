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
    movestep(512,0)
}

/*
 * a more detailed example
 */
jon_castle { _jon_castle(get("floor"), add(160, get("floor"))) }

buttresses(f,c,count) {
    for(0, count,
        box(add(f, 128), add(f,128), 160, 32, 16)
        movestep(0,16)
        box(add(f, 128), c, 160, 32, 16)
        movestep(64,-16)
    )
}

_jon_castle(f,c) {
    !jon_castle
    unpegged

    floor("RROCK19")
    mid("STONE2")

    -- extra door corridor
    pushpop(
      movestep(0, 192)
      box(f, add(f,96), 160, 32,128)
    )

    ceil("F_SKY1")

    -- main space
    movestep(32,32)
    box(f, add(f, c), 160, 448, 448)

    -- west and north wall
    movestep(32,-32)
    buttresses(f,c,6)
    rotright movestep(32,32)
    movestep(32,-32)
    buttresses(f,c,6)
    rotright

    -- exit door wall
    movestep(96,0)
    buttresses(f,c,0)
    movestep(224,0)
    buttresses(f,c,0)

    -- entrance door wall
    movestep(64,96) rotright
    buttresses(f,c,0)
    movestep(224,0)
    buttresses(f,c,0)

    unpegged
    ^jon_castle
    movestep(512,512)
    rotright

    -- extra exit door corridor
    pushpop(
      movestep(-32, 192)
      box(f, add(f,96), 160, 32,128)
    )
}
