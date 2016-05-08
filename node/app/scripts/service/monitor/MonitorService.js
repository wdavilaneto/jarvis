'use strict';

/* Services */
angular.module('jarvisApp').factory('MetricsService',function ($http) {
        return {
        get: function() {
            var promise = $http.get('/jarvis/api/metrics/metrics').then(function(response){
                return response.data;
            });
            return promise;
        }
    };
});

angular.module('jarvisApp').factory('ThreadDumpService', function ($http) {
    return {
        dump: function() {
            var promise = $http.get('/jarvis/api/dump').then(function(response){
                return response.data;
            });
            return promise;
        }
    };
});

angular.module('jarvisApp').factory('HealthCheckService', function ($rootScope, $http) {
    return {
        check: function() {
            var promise = $http.get('/jarvis/api/health').then(function(response){
                return response.data;
            });
            return promise;
        }
    };
});