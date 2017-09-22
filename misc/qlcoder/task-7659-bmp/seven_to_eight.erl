-module(seven_to_eight).
-compile(export_all).
-define(IN_IMG_PATH, "145752260153647.bmp").
-define(OUT_IMG_PATH, "145752260153647o.bmp").


solve() ->
	{ok,BS} = fread(), Part1 = part1(),
	<<_:54/binary,BS1/binary>> = BS,
	<<Part2:1024/binary,BS2/binary>> = BS1,
	Result = loop(BS2, <<Part1/binary,Part2/binary>>),
	fwrite(Result).


loop(<<>>, Acc) ->
	Acc;
loop(<<X:7,R/bitstring>>, Acc) ->
	loop(R, <<Acc/binary,X:8>>).


fread() ->
	file:read_file(?IN_IMG_PATH).

fwrite(Bin) ->
	file:write_file(?OUT_IMG_PATH, Bin).


part1() ->
<<16#42,16#4D
,16#36,16#58,16#00,16#00
,16#00,16#00,16#00,16#00
,16#36,16#04,16#00,16#00
,16#28,16#00,16#00,16#00
,16#E0,16#00,16#00,16#00
,16#60,16#00,16#00,16#00
,16#01,16#00,16#08,16#00
,16#00,16#00,16#00,16#00
,16#00,16#54,16#00,16#00
,16#00,16#00,16#00,16#00
,16#00,16#00,16#00,16#00
,16#00,16#01,16#00,16#00
,16#7F,16#00,16#00,16#00
>>.



