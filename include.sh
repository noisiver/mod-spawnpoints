#!/usr/bin/env bash
MOD_SPAWNPOINTS_ROOT="$( cd "$( dirname "${BASH_SOURCE[0]}" )/" && pwd )"

source $MOD_SPAWNPOINTS_ROOT"/conf/conf.sh.dist"

if [ -f $MOD_SPAWNPOINTS_ROOT"/conf/conf.sh" ]; then
    source $MOD_SPAWNPOINTS_ROOT"/conf/conf.sh"
fi
