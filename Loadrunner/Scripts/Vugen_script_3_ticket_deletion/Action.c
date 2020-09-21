Action()
{
	lr_start_transaction("Vugen_script_3_ticket_deletion");
	
	lr_start_transaction("goToSite");
	
//  web_set_sockets_option("SSL_VERSION", "2&3");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");
		
	web_reg_find("Text=signOff=true",
		LAST);
		
/*Correlation comment - Do not change!  Original value='129647.34945322zzziHDfpfDHftAAVcptVDccf' Name ='userSession' Type ='ResponseBased'*/
//	web_reg_save_param_attrib(
//		"ParamName=userSession",
//		"TagName=input",
//		"Extract=value",
//		"Name=userSession",
//		"Type=hidden",
//		SEARCH_FILTERS,
//		"IgnoreRedirections=No",
//		"RequestUrl=*/nav.pl*",
//		LAST);

	web_reg_save_param_ex(
        "ParamName=userSession",
        "LB=<input type=\"hidden\" name=\"userSession\" value=\"",
        "RB=\"",
        SEARCH_FILTERS,
        "IgnoreRedirections=off",
        "Scope=Body",
        "RequestUrl=*",
        LAST);

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("goToSite", LR_AUTO);
	
	lr_think_time(9);

	lr_start_transaction("login");

	web_revert_auto_header("Sec-Fetch-User");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");
	
	web_reg_find("Fail=NotFound",
		"Text=User password was correct",
		LAST);

	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t4.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=login.x", "Value=58", ENDITEM,
		"Name=login.y", "Value=6", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);

	lr_end_transaction("login",LR_AUTO);
	
	lr_think_time(29);

	lr_start_transaction("click_itinerary");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");
	
	web_reg_find("Text=<!-- Flight #1 -->",
		LAST);
	
//name="flightID" value="128000384-2337-JB"
/*Correlation comment - Do not change!  Original value='128012650-812-JB' Name ='flightID' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=flightID",
		"TagName=input",
		"Extract=value",
		"Name=flightID",
		"Type=hidden",
		"Ordinal=All",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		//"Ordinal=All",
		"RequestUrl=*/itinerary.pl*",
		LAST);
		
//		web_reg_save_param_attrib(
//		"ParamName=cgifields",
//		"TagName=input",
//		"Extract=value",
//		"Name=.cgifields",
//		"Type=hidden",
//		"Ordinal=All",
//		SEARCH_FILTERS,
//		"IgnoreRedirections=No",
//		//"Ordinal=All",
//		"RequestUrl=*/itinerary.pl*",
//		LAST);

	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("click_itinerary",LR_AUTO);
	
	lr_think_time(39);

	lr_start_transaction("click_cancel_checked");

	web_add_header("Origin", 
		"http://localhost:1080");
	
	web_submit_form("web_submit_form",
		    ITEMDATA,
		    "Name=1", "Value=on", ENDITEM,
		    "Name=removeFlights.x", "Value=72", ENDITEM,
		    "Name=removeFlights.y", "Value=9", ENDITEM,
		    EXTRARES,
		    "URL=http://localhost:1080/cgi-bin/itinerary.pl",
		    "Referer=http://localhost:1080/cgi-bin/itinerary.pl",ENDITEM,
			LAST );

//	web_submit_data("itinerary.pl", 
//		"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
//		"Method=POST", 
//		"TargetFrame=", 
//		"RecContentType=text/html", 
//		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
//		"Snapshot=t6.inf", 
//		"Mode=HTML", 
//		ITEMDATA, 
//		"Name=1", "Value=on", ENDITEM, 
//		"Name=flightID", "Value=2229-784-JB", ENDITEM, 
//		"Name=flightID", "Value=128000397-1594-JB", ENDITEM, 
//		"Name=flightID", "Value=128000397-2363-JB", ENDITEM, 
//		"Name=flightID", "Value=128000397-3132-JB", ENDITEM, 
//		"Name=flightID", "Value=128000397-3901-JB", ENDITEM, 
//		"Name=flightID", "Value=128000397-4671-JB", ENDITEM, 
//		"Name=flightID", "Value=128000397-5440-JB", ENDITEM, 
//		"Name=flightID", "Value=128000397-6209-JB", ENDITEM, 
//		"Name=flightID", "Value=128000397-6978-JB", ENDITEM, 
//		"Name=flightID", "Value=128000764-7741-JB", ENDITEM, 
//		"Name=flightID", "Value=128000764-8510-JB", ENDITEM, 
//		"Name=flightID", "Value=128000397-9286-JB", ENDITEM, 
//		"Name=flightID", "Value=128000397-10055-JB", ENDITEM, 
//		"Name=flightID", "Value=128000397-10824-JB", ENDITEM, 
//		"Name=removeFlights.x", "Value=72", ENDITEM, 
//		"Name=removeFlights.y", "Value=9", ENDITEM, 
//		"Name=.cgifields", "Value=6", ENDITEM, 
//		"Name=.cgifields", "Value=11", ENDITEM, 
//		"Name=.cgifields", "Value=3", ENDITEM, 
//		"Name=.cgifields", "Value=7", ENDITEM, 
//		"Name=.cgifields", "Value=9", ENDITEM, 
//		"Name=.cgifields", "Value=12", ENDITEM, 
//		"Name=.cgifields", "Value=2", ENDITEM, 
//		"Name=.cgifields", "Value=14", ENDITEM, 
//		"Name=.cgifields", "Value=8", ENDITEM, 
//		"Name=.cgifields", "Value=1", ENDITEM, 
//		"Name=.cgifields", "Value=4", ENDITEM, 
//		"Name=.cgifields", "Value=13", ENDITEM, 
//		"Name=.cgifields", "Value=10", ENDITEM, 
//		"Name=.cgifields", "Value=5", ENDITEM, 
//		LAST);

	lr_end_transaction("click_cancel_checked",LR_AUTO);
	
	lr_think_time(38);

	lr_start_transaction("click_log_out");

	web_revert_auto_header("Sec-Fetch-User");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("click_log_out",LR_AUTO);

	lr_end_transaction("Vugen_script_3_ticket_deletion",LR_AUTO);

	return 0;
}