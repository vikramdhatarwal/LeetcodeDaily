class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,string arriveBob, string leaveBob) {

        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int AAM = stoi(arriveAlice.substr(0, 2));
        int AAD = stoi(arriveAlice.substr(3, 2));

        int ALM = stoi(leaveAlice.substr(0, 2));
        int ALD = stoi(leaveAlice.substr(3, 2));

        int BAM = stoi(arriveBob.substr(0, 2));
        int BAD = stoi(arriveBob.substr(3, 2));

        int BLM = stoi(leaveBob.substr(0, 2));
        int BLD = stoi(leaveBob.substr(3, 2));

        auto convert = [&](int month, int day) {
            int total = day;

            for (int i = 0; i < month - 1; i++) {
                total += days[i];
            }

            return total;
        };

        int aStart = convert(AAM, AAD);
        int aEnd = convert(ALM, ALD);
        int bStart = convert(BAM, BAD);
        int bEnd = convert(BLM, BLD);

        int start = max(aStart, bStart);
        int end = min(aEnd, bEnd);

        if (start > end) return 0;

        return end - start + 1;
    }
};