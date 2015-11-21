#ifndef SOCKET_LIBRARY
#define SOCKET_LIBRARY

#include <iostream>
#include <string>

#include <cstdio>
#include <cstdlib>
#include <cerrno>
#include <cstring>

#ifdef _WINDOWS
#else
#include <netdb.h> 
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#endif

class Socket {
	public:
		Socket()
			:	Socket(0)
		{}

		Socket(size_t portno)
			:	Socket(portno, false)
		{}

		Socket(size_t portno, bool verbose)
			:	Socket(portno, verbose, "localhost")
		{}

		Socket(size_t portno, bool verbose, const std::string& host)
			:	m_portno(portno),
				m_verbose(verbose),
				m_host(host),
				m_sockfd(-1)
		{}

		void setPort(size_t portno) {
			m_portno = portno;
		}

		void setVerbose(bool verbose) {
			m_verbose = verbose;
		}

		void setHost(const std::string& host) {
			m_host = host;
		}

		size_t getPort() const {
			return m_portno;
		}

		bool getVerbose() const {
			return m_verbose;
		}

		const std::string& getHost() const {
			return m_host;
		}

		void error(const std::string& msg) const {
			std::cout << msg << ": " << strerror(errno) << std::endl;
		}

		bool connectSocket() {
			struct sockaddr_in serv_addr;
			struct hostent* server;

			if (m_verbose) {
				std::cout << "Creating socket..." << std::endl;
			}
			m_sockfd = socket(AF_INET, SOCK_STREAM, 0);
			if (m_sockfd < 0) {
				error("ERROR (failed opening socket)");
				return false;
			}
			if (m_verbose) {
				std::cout << "Connecting to server..." << std::endl;
			}
			server = gethostbyname(m_host.c_str());
			if (server == NULL) {
				error("ERROR (no such host)");
				return false;
			}
			char* serv_ip = inet_ntoa(*(struct in_addr *)*server->h_addr_list);
			if (m_verbose) {
				std::cout << "Server is " << serv_ip << ":" << m_portno << std::endl;
			}
			bzero((char *) &serv_addr, sizeof(serv_addr));
			serv_addr.sin_family = AF_INET;
			serv_addr.sin_addr.s_addr = inet_addr(serv_ip);
			serv_addr.sin_port = htons(m_portno);
			if (connect(m_sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
				error("ERROR (failed connecting socket)");
				return false;
			}
			return true;
		}

		bool closeSocket() {
			if (close(m_sockfd) < 0) {
				error("ERROR (failed disconnecting socket)");
				return false;
			}
			return true;
		}

		bool recvMsg(char* buffer, size_t buffer_size) {
			int64_t bytes = read(m_sockfd, buffer, buffer_size);
			if (bytes < 0) {
				error("ERROR (reading from socket)");
				return false;
			}
			if (m_verbose) {
				std::cout << "Recv success, bytes: " << bytes << std::endl;
			}
			return true;
		}

		bool sendMsg(const char* buffer, size_t buffer_size) {
			int64_t bytes = write(m_sockfd, buffer, buffer_size);
			if (bytes < 0) {
				error("ERROR (writing to socket)");
				return false;
			}
			if (m_verbose) {
				std::cout << "Send success, bytes: " << bytes << std::endl;
			}
			return true;
		}

	private:
		size_t		m_portno;
		bool		m_verbose;
		std::string	m_host;
		int			m_sockfd;
};

#endif
