DROP TABLE IF EXISTS `mod_spawnpoints`;
CREATE TABLE `mod_spawnpoints` (
    `team_id` INT NOT NULL,
    `map_id` INT NOT NULL,
    `area_id` INT NOT NULL,
    `pos_x` FLOAT NOT NULL,
    `pos_y` FLOAT NOT NULL,
    `pos_z` FLOAT NOT NULL,
    `orientation` FLOAT NOT NULL,
    `comment` CHAR(50) NULL DEFAULT '',
    PRIMARY KEY (`team_id`)
)
COMMENT='Spawn points for Assistant'
COLLATE='utf8mb4_general_ci';

INSERT INTO `mod_spawnpoints` (`team_id`, `map_id`, `area_id`, `pos_x`, `pos_y`, `pos_z`, `orientation`, `comment`) VALUES (0, 0, 1519, -8830.44, 626.666, 93.9829, 0.682076, 'Alliance - Stormwind City');
INSERT INTO `mod_spawnpoints` (`team_id`, `map_id`, `area_id`, `pos_x`, `pos_y`, `pos_z`, `orientation`, `comment`) VALUES (1, 1, 1637, 1630.78, -4412.99, 16.5677, 0.080535, 'Horde - Orgrimmar');
