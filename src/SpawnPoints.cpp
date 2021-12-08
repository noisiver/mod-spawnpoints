#include "MapMgr.h"
#include "Player.h"
#include "ScriptMgr.h"

struct SpawnPoints
{
    uint32 MapId;
    float X;
    float Y;
    float Z;
    float O;
};

std::vector<SpawnPoints> spawnPoints;

class SpawnPointData : public WorldScript
{
    public:
        SpawnPointData() : WorldScript("SpawnPointData") { }

        void OnStartup() override
        {
            QueryResult result = WorldDatabase.Query("SELECT `team_id`, `map_id`, `pos_x`, `pos_y`, `pos_z`, `orientation` FROM `mod_spawn_points`");

            if (!result)
                return;

            do
            {
                Field* fields = result->Fetch();
                uint32 TeamId = fields[0].GetUInt32();

                spawnPoints.push_back(SpawnPoints());
                spawnPoints[TeamId].MapId = fields[1].GetUInt32();
                spawnPoints[TeamId].X = fields[2].GetFloat();
                spawnPoints[TeamId].Y = fields[3].GetFloat();
                spawnPoints[TeamId].Z = fields[4].GetFloat();
                spawnPoints[TeamId].O = fields[5].GetFloat();
            } while (result->NextRow());
        }
};

class SetSpawnPoint : public PlayerScript
{
    public:
        SetSpawnPoint() : PlayerScript("SetSpawnPoint") {}

        void OnCreate(Player* player) override
        {
            if (player->getClass() == CLASS_DEATH_KNIGHT)
                return;

            uint32 mapId = spawnPoints[player->GetTeamId()].MapId;
            float x = spawnPoints[player->GetTeamId()].X;
            float y = spawnPoints[player->GetTeamId()].Y;
            float z = spawnPoints[player->GetTeamId()].Z;
            float orientation = spawnPoints[player->GetTeamId()].O;

            const WorldLocation &location = WorldLocation(mapId, x, y, z, orientation);

            player->Relocate(&location);
            player->SaveToDB(false, false);
        }
};

void AddSpawnPointsScripts()
{
    new SpawnPointData();
    new SetSpawnPoint();
}
