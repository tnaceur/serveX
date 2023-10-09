#include "location_data.hpp"

/*  location_data Constructor  */
location_data::location_data() : _autoIndex(false), _autoUpload(false), _isEmptyLocation(false) {}
location_data::location_data(const std::string& path) : _autoIndex(false), _autoUpload(false), _isEmptyLocation(false), _path(path) {}


/*  location_data Setters  */
void location_data::setRoot( std::string const& root)
{
    this->_root = root;
}
void location_data::setUploadPath( std::string const& uploadPath)
{
    this->_uploadPath = uploadPath;
}
void location_data::setCgiPath( std::string const& cgiPath)
{
    this->_cgiPath = cgiPath;
}
void location_data::setAutoIndex(bool autoIndex)
{
    this->_autoIndex = autoIndex;
}
void location_data::setIsEmptyLocation(bool isempty)
{
    _isEmptyLocation = isempty;
}
void location_data::setAutoUpload(bool autoUpload)
{
    this->_autoUpload = autoUpload;
}
void location_data::setIndex( std::string const& index)
{
    this->_indexes.push_back(index);
}
void location_data::setAllowedMethod( int method)
{
    this->_allowedMethods.push_back(method);
}
void location_data::setRedirection( int status, const std::string& path )
{
    _redirection.first = status;
    _redirection.second = path;
}

/*  location_data Getters  */
bool    location_data::getAutoIndex() const
{
    return _autoIndex;
}
bool    location_data::getAutoUpload() const
{
    return _autoUpload;
}
bool    location_data::getIsEmptyLocation() const
{
    return _isEmptyLocation;
}
std::string location_data::getRoot() const
{
    return _root;
}
std::string location_data::getPath() const
{
    return _path;
}
std::string location_data::getUploadPath() const
{
    return _uploadPath;
}
std::string location_data::getCgiPath() const
{
    return _cgiPath;
}
std::vector<std::string> location_data::getIndexes() const
{
    return _indexes;
}
std::vector<int> location_data::getAllowedMethods() const
{
    return _allowedMethods;
}
const   std::pair<int, std::string>&   location_data::getlocationRedirections() const
{
    return _redirection;
}


/*LocationCofig Helper Functions */
bool    location_data::isEmpty() const
{
    if (_root.empty() && _indexes.size() < 1 && _allowedMethods.size() < 1 && _redirection.second.empty() && _uploadPath.empty() && _cgiPath.empty())
        return true;
    return false;
}
bool    location_data::isLocationValidAndReady( void )
{
    if (_path.empty() || _root.empty() || !_indexes.size() || !_allowedMethods.size())
        return false;
    return true;
}