char* get_uname(int uid)
{
	struct passwd pwd = *getpwuid(uid);
	return pwd.pw_name;
}

