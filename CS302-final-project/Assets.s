# John Ripley's trick for binary embedding via x86 asm
# ref https://stackoverflow.com/a/4910421
.section .rodata

.global GolfBallTexture
.type GolfBallTexture, @object
GolfBallTexture:
	.incbin "assets/golf-ball.png"
GolfBallTextureEnd:
	.byte 0 # Null terminate (just in case)

.global GolfBallTextureLen
.type GolfBallTextureLen, @object
.balign 8
GolfBallTextureLen:
	.quad GolfBallTextureEnd - GolfBallTexture
