//Name - Sanjiv Kumar
//Chitkara ID - 2110994853 

/* In this task my project is based on storing the datas of a cricket match.
1. i want to store the data of each player and made runs by him.
2. To find the total score made by team and avg score of a player in that team and also which player has made highest run and took wicket in a team.
3. To find the highest scorrer in the whole series of a match and avg score in whole matches.
*/

#include "splashkit.h"
#include <string>
#include <vector>
using std::vector;
using namespace std;

//Declaring player data object

struct player_data
{
    string player_name;
    string role;
    int age;
    int run;
    int six;
    int four;
    int score;
    int wicket;

    int score_player(player_data &player)
    {
        score = run + six * 6 + four * 4;
        return score;
    }
};

//Declaring Team data object

struct team_data:player_data
{
    string team_name;
    int team_score;
    int avg_score;
    player_data player;
    vector<player_data> players;
    
//calculating players avg score

    int players_avg_score(team_data &team)
    {
        for(int i=0; i < players.size(); i++)
        {  
            team_score += team.players[i].score/players.size(); 
        }
        return team_score;
    }

//calculating team score

    int all_team_score(team_data &team)
    {
        for(int i=0; i < players.size(); i++)
        {  
            team_score += team.players[i].score; 
        }
        return team_score;
    }

//finding higheat score player

    int highest_score_player(team_data &team)
    {
        int count = 0;
        int max_player = team.players[0].score;
        for(int i = 0; i < players.size(); i++)
        {
            if(max_player < team.players[i].score)
            {
                max_player = team.players[i].score;
            }
            count++;
        }
        return count;
    }

//finding highest wicket player

    int highest_wicket_player(team_data &team)
    {
        int count = 0;
        int max_player = team.players[0].wicket;
        for(int i = 0; i < players.size(); i++)
        {
            if(max_player < team.players[i].wicket)
            {
                max_player = team.players[i].wicket;
            }
            count++;
        }
        return count;
    }
};

//Decalring game data object

struct game_data:team_data
{
    string game_name;
    int year;
    int avg_game;
    team_data team;
    vector<team_data> teams;

//calculatinf avg score in that particular session
    
    int avg_score_year(game_data &game)
    {
        for(int i=0; i < players.size(); i++)
        {  
            avg_game += game.teams[i].team_score/players.size(); 
        }
        return avg_game;
    }

//finding highest score team

    int highest_score_team(game_data &game)
    {
        int count = 0;
        int max_team = game.teams[0].team_score;
        for(int i = 0; i < teams.size(); i++)
        {
            if(max_team < game.teams[i].team_score)
            {
                max_team = game.teams[i].team_score;
            }
            count++;
        }
        return count;
    }
};

//making team option index using enum

enum team_option
{
    DISPLAY_PLAYERS,
    ADD_PLAYER,
    FINISH_UP
};

//making game option index using enum

enum game_option
{
    DISPLAY_TEAMS,
    ADD_TEAMS,
    UPDATE_TEAMS,
    FINISH
};

string read_string(string prompt)
{    
    string result;
    write(prompt);
    result = read_line();
    return result;
}

int read_integer(string prompt)
{   
    string line;
    int result;

    line = read_string(prompt);
    while(not is_integer(line))
    {
        write_line("please enter a number: ");
        line = read_string(prompt);
    }
    result = convert_to_integer(line);
    return result;
}

int read_integer_range(string prompt, int min, int max)
{
    int line;
    line = read_integer(prompt);

    while(line < min or line > max)
    {
        write_line("please rate between " + to_string(min) + " to " +  to_string(max));
        line = read_integer(prompt);
    }
    return line;
}

//taking input in player data object

player_data read_knight()
{
    player_data result;
    string player;
    string role;

    write_line("===player===");
    result.player_name = read_string("Enter player's name: ");
    result.age = read_integer("Enter age: ");
    result.role = read_string("Enter the role of player in this game As Batsman/Baller: ");
    result.run = read_integer("Enter run: ");
    result.six = read_integer("Enter the number of sixer boundary: ");
    result.four = read_integer("Enter the number of four run boundary: ");
    result.wicket = read_integer_range("Enter the number of wickets: ", 1, 10);
    return result;
}

//taking input in team data

team_data read_team()
{
    team_data result;
    result.team_name = read_string("Enter team name: ");
    return result;
}

//taking input in game data

game_data read_game()
{
    game_data result;
    result.game_name = read_string("Enter game name: ");
    result.year = read_integer("Enter game year: ");
    return result;
}

//decalaring function to add player

void add_player(team_data &team)
{
    player_data new_knight = read_knight();
    team.players.push_back(new_knight);
}

//declaring function to add team

void add_team(game_data &game)
{
    team_data new_team = read_team();
    game.teams.push_back(new_team);
}

//declaring function to print player data

void write_player(player_data &player)
{
    write_line("======"+ player.player_name+ "======");
    write_line("===player's profile===");
    write_line("player's age is " + to_string(player.age));
    write_line("player's role is as " + player.role);
    write_line("player's score is " + to_string(player.score_player(player)));
    write_line("player has taken " + to_string(player.wicket));
}

//declaring function to print team data

void write_team(team_data &team)
{
    write_line("==========: " + team.team_name + ":==========");
    for(int i = 0; i < team.players.size(); i++)
    {
        write_line("===PEOPLE===");
        write_line("Index: " + to_string(i));
        write_player(team.players[i]);
    }
    write_line("==========: team performancr card: ==========");
    write_line("score of team " + team.team_name + " "+to_string(team.players_avg_score(team)));
    write_line("Avg score of players in team " + team.team_name + " "+to_string(team.players_avg_score(team)));
    write_line("Highest scorrer: " + to_string(team.players[team.highest_score_player(team)].score) + " made by player: "  + team.players[team.highest_score_player(team)].player_name);
    write_line("Highest wicket took: " + to_string(team.players[team.highest_score_player(team)].wicket) + " by player: "  + team.players[team.highest_wicket_player(team)].player_name);
}

//declaring function to print whole game seasion data

void write_game(game_data &game)
{
    write_line("==========: " + game.game_name + " " + to_string(game.year) + " :==========");
    for(int i = 0; i < game.teams.size(); i++)
    {
        write_team(game.teams[i]);
    }
    write_line("====: game overview :====");
    write_line("Avg score of this year in whole series: " + to_string(game.avg_score_year(game)));
    write_line("=====:Highest scorrer and winner team :=====");
    write_team(game.teams[game.highest_score_team(game)]);
}

//guiding lines to select option and making simpler to select right option for user than developer

team_option read_team_update_option()
{
    int result;
    write_line("");
    write_line("== Update team ==");
    write_line("");
    write_line("1. Display the players");
    write_line("2. Add player");
    write_line("3. Finish Update");
    result = read_integer("Choose an option: ");
    return static_cast<team_option>(result - 1);
}

//guiding lines to select option and making simpler to select right option for user than developer

game_option read_game_option()
{
    int result;
    write_line("");
    write_line("== Update game ==");
    write_line("");
    write_line("1. Display the teams");
    write_line("2. Add a team data");
    write_line("3. Update teams");
    write_line("4. Finish Update");
    result = read_integer("Choose an option: ");
    return static_cast<game_option>(result - 1);
}

//declaring function for selecting functionality

void update_team(team_data &team)
{
    team_option option;
    do
    {
        option = read_team_update_option();

        switch (option)
        {
            case DISPLAY_PLAYERS:
            write_team(team);
            break;

            case ADD_PLAYER:
            add_player(team);
            break;

            case FINISH_UP:
            break;
            
            default:
            write_line("Invalid response,Please enter a valid response");
        }
    } while (option != FINISH_UP);
}

//declaring function for selecting functionality

void update_game(game_data &game)
{
    game_option option;
    int index = 0;
    do
    {

        option = read_game_option();

        switch (option)
        {
         
            case DISPLAY_TEAMS:
            write_game(game);
            break;

            case ADD_TEAMS:
            add_team(game);
            break;

            case UPDATE_TEAMS:
            index = read_integer("please enter the index of team you want to change the data: ");
            update_team(game.teams[index]);
            break;

            case FINISH:
            break;
            
            default:
            write_line("please choose correct option!!!");
        }
    } while (option != FINISH);
}

int main()
{

//Declaration of statement in main function

    game_data game;
    game = read_game();
    update_game(game);
    return 0;
}