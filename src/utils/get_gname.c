char* get_gname(int gid)
{
	struct group grp = *getgrgid(gid);
	return grp.gr_name;
}