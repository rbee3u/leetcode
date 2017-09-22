SELECT
	IF(MOD(id, 2) = 0,
		id - 1,
		IF(id = (SELECT COUNT(*) FROM seat),
			id,
			id + 1)) as id,
	student
FROM seat ORDER BY id;
