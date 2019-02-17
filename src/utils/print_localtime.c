// https://github.com/RachitaS/ls_command_Implementation/commit/4bb7885c0bf9e37ec454cc47b1e81afbde1a6c4e#diff-3322ec1e92753bd43a913dc25e7984c4

void print_localtime(time_t mtime)
{
	struct tm *tm = localtime(&mtime);
	char* month[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
	printf("%*s %*d %02d:%02d ",3,month[(tm->tm_mon)],2, tm->tm_mday, tm->tm_hour, tm->tm_min);

}