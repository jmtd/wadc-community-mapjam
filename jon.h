/*
 * vim: set ft=wadc:
 *
 * Jon's WadC mapjam room, first attempt
 */
#"decoration.h"

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
        box(add(f, 128), add(f,128), 160, 32, 8)
        movestep(0,8)
        box(add(f, 128), c, 160, 32, 16)
        movestep(64,-8)
    )
}

_jon_castle(f,c) {
    !jon_castle
    unpegged

    floor("RROCK19") floor("MFLR8_1")
    mid("STONE2") bot("STONE2") top("STONE2")

    -- extra door corridor
    pushpop(
      movestep(0, 192)
      box(f, add(f,96), 160, 32,128)
    )

    ceil("F_SKY1")

    -- main space

    movestep(128,128)
    quad(
        left(96)   pushpop( movestep(-64,-24) buttresses(f,c,0) )
        right(256)
        rotright
        pushpop(movestep(32,-24) buttresses(f,c,0))
        straight(96)
    )
    rightsector(f,add(f, c), 160)

    -- inset floor
    pushpop(
        floor("RROCK19")
        movestep(32,0)
        quad (step(32,32) straight(200) rotright)
        innerrightsector(sub(f,16),c,160)
    )
    pushpop(movestep(128,128) burnttree thing)

    -- west wall
    pushpop(
        movestep(48,-120)
        buttresses(f,c,2)
    )
    -- north wall
    pushpop(
        move(376) rotright
        move(48)
        buttresses(f,c,2)
    )

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
