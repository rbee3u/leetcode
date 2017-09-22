-module(mysql_table).
-export([start/0]).
-compile(export_all).


-define(TARGET_PAGE, 23333).
-define(ONE_PAGE_NUM,   20).
-define(SUBTABLE_NUM,   10).
-define(TABLE_IDLIST, [0,1,2,3,4,5,6,7,8,9]).


start() ->
	inets:start(),
	DefaultOffset = (?TARGET_PAGE - 1)
		* ?ONE_PAGE_NUM div ?SUBTABLE_NUM,
	InitList = [{TableID,DefaultOffset}
			|| TableID <- ?TABLE_IDLIST],
	loop(InitList).


loop(List) ->
	List2 = lists:map(fun({TableID,Offset}) ->
		HalfNumber = ?ONE_PAGE_NUM * 2,
		FavsList = select(TableID, Offset-HalfNumber
									, HalfNumber * 2),
		{TableID,Offset,FavsList}
	end, List),
	GMid = gmid(List2),
	List3 = [func(E, GMid) || E <- List2],
	case isend(List3) of
	true ->
		output(List3);
	_ ->
		List4 = [{ID,Of} || {ID,_,Of,_,_} <- List3],
		loop(List4)
	end.


output(List) ->
	Smaller = lists:append([Sm || {_,_,_,Sm,_} <- List]),
	Smaller2 = lists:reverse(lists:sort(Smaller)),
	Smaller3 = lists:sublist(Smaller2, ?ONE_PAGE_NUM),
	Answer = lists:sum([E div 10 || E <- Smaller3]),
	io:format("the answer is: ~w~n", [Answer]).


func({TableID,Offset,FavsList}, GMid) ->
	{Smaller,Bigger} = lists:partition(fun(Favs) ->
		Favs =< GMid
	end, FavsList),
	Delta = (length(Bigger)-length(Smaller)) div 2,
	{TableID,Offset,Offset+Delta,Smaller,Bigger}.


isend(List) ->
	lists:all(fun({_,_,_,Smaller,_}) ->
		length(Smaller) >= ?ONE_PAGE_NUM
	end, List).


gmid(List) ->
	List2 = lists:append([V || {_,_,V} <- List]),
	List3 = lists:reverse(lists:sort(List2)),
	lists:nth(length(List3) div 2 + 1, List3).


select(TableID, Offset, Number) ->
	Url = io_lib:format("http://www.qlcoder.com/train/mysql"
			"?table=~w&a=~w&b=~w", [TableID,Offset,Number]),
	io:format("~s~n", [Url]),
	{ok,{_,_,DRet}} = httpc:request(get, {Url,[]}, [], []),
	{JRet} = jiffy:decode(DRet),
	_FavsList = lists:map(fun({Elem}) ->
		Favs = proplists:get_value(<<"favs">>, Elem),
		Favs * ?SUBTABLE_NUM + TableID
	end, proplists:get_value(<<"data">>, JRet)).



