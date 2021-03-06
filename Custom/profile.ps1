Set-Alias subl "C:\Program Files\Sublime Text 3\sublime_text.exe"

function run { 
	g++ -D CUST_DEBUG -Wall -Wshadow $args 
}

function new {
	param ( 
		[string[]]$F 
	)
	[string[]]$ext = ".cpp"
	$filename = $F.Trim() + $ext.Trim()
	$startTime = Get-Date

	Write-Host ""
	Write-Host "$startTime  " -ForegroundColor yellow
	if( (Test-Path -Path E:\PRO\Comp\default.cpp) ){
		if( !(Test-Path -Path $filename) ){
			Write-Host "Create Mode:"$filename -ForegroundColor blue
			Copy-Item E:\PRO\Comp\default.cpp $filename
		} else{
			Write-Host "Error:"$filename" already exists" -ForegroundColor red
		}
	} else{
		Write-Host "Error default.cpp not found"  -ForegroundColor red
	}

	subl $filename
	Write-Host ""
}
